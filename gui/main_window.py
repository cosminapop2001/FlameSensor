from PySide6.QtWidgets import QMainWindow, QApplication, QVBoxLayout, QHBoxLayout, QWidget, QGroupBox, QLabel, QPushButton, QLineEdit, QTextEdit
from PySide6.QtGui import QIcon, QFont
from PySide6.QtCore import Qt, QTimer
import pyqtgraph as pg
import sys
import random
import serial


class MainWindow(QMainWindow):
    promotie: str = "2023-2024"
    project_name: str = "FRDM-KL25Z with Flame Sensor"
    team: list[str] = ["Pop Daria Cosmina", "Lascuzeanu Stefan"]

    def __init__(self):
        super().__init__()
        self.setWindowTitle(f"Proiect Microprocesoare {self.promotie}")
        self.setWindowIcon(QIcon("./icon.png"))

        primary_layout = QVBoxLayout()

        project_label = QLabel(self.project_name)
        project_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        project_label.setFont(QFont("Arial", 14, QFont.Weight.Bold))
        primary_layout.addWidget(project_label)

        secondary_layout = QHBoxLayout()
        tertiary_layout = QVBoxLayout()

        team_box = QGroupBox("Membrii echipei")
        bold_font = QFont()
        bold_font.setBold(True)
        team_box.setFont(bold_font)

        first_member = QLabel(f"Membru 1: {self.team[0]}")
        second_member = QLabel(f"Membru 2: {self.team[1]}")
        team_box_layout = QVBoxLayout()
        team_box_layout.addWidget(first_member, 1)
        team_box_layout.addWidget(second_member, 1)
        team_box.setLayout(team_box_layout)


        # Inițializare conexiune serială
        self.ser = serial.Serial('COM3', 14400, timeout=1)


        bcd_box = QGroupBox("BCD Display")
        bcd_box.setFont(bold_font)
        bcd_box_layout = QVBoxLayout()
        self.bcd_display_label = QLabel()
        self.bcd_display_label.setFont(QFont("Arial", 120))
        self.bcd_display_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.bcd_display_label.setText("2")
        bcd_box_layout.addWidget(self.bcd_display_label)
        bcd_box.setLayout(bcd_box_layout)

        control_panel_box = QGroupBox("Control Panel")
        control_panel_box.setFont(bold_font)

        button3 = QPushButton("Send")
        button3.clicked.connect(self.send_input)
        self.line_edit = QLineEdit()
        self.line_edit.setAlignment(Qt.AlignmentFlag.AlignBottom)
        line_edit_label = QLabel("Input:", parent=self.line_edit)
        control_panel_box_layout = QVBoxLayout()
        control_panel_box_layout.setSpacing(5)
        control_panel_box_layout.addStretch()
        control_panel_box_layout.addWidget(line_edit_label)
        control_panel_box_layout.addWidget(self.line_edit, 1)
        control_panel_box_layout.addWidget(button3, 1)
        control_panel_box.setLayout(control_panel_box_layout)

        tertiary_layout.addWidget(team_box, 1)
        tertiary_layout.addWidget(bcd_box, 4)
        tertiary_layout.addWidget(control_panel_box, 1)

        self.plot_widget = pg.PlotWidget()
        self.plot_data = {'time': [], 'adc_values': []}
        self.plot_widget.plot(self.plot_data['time'], self.plot_data['adc_values'])
        
        line1 = pg.InfiniteLine(pos=64910, angle=0, pen=pg.mkPen('r', width=2))
        line2 = pg.InfiniteLine(pos=64920, angle=0, pen=pg.mkPen('r', width=2))
        self.plot_widget.addItem(line1)
        self.plot_widget.addItem(line2)

        secondary_layout.addWidget(self.plot_widget, 3)
        secondary_layout.addLayout(tertiary_layout, 1)

        primary_layout.addLayout(secondary_layout, 4)
        self.text_edit = QTextEdit()
        self.text_edit.setReadOnly(True)

        widget = QWidget()
        widget.setLayout(primary_layout)
        self.setCentralWidget(widget)

        self.timer = QTimer()
        self.timer.timeout.connect(self.update_data)
        self.timer.start(1000)  # Actualizează datele la fiecare 1 secundă

    def send_input(self):
        input_text = self.line_edit.text()
        self.line_edit.clear()
        self.text_edit.insertPlainText(f"INPUT: {input_text}\n")

    def read_uart_data(self):
        # Funcție fictivă pentru citirea datelor UART
        try:
            if self.ser.in_waiting > 0:
                data = self.ser.read(7).decode('utf-8')
                number = int(data[:5])
                return number
        except Exception as e:
                print(f"Error reading UART data: {e}", file=sys.stderr)
        return 0 

    def update_data(self):
        new_adc_value = self.read_uart_data()
        if new_adc_value ==0:
                self.bcd_display_label.setText("-")
        if new_adc_value is not None and new_adc_value != 0:
            current_time = len(self.plot_data['time'])
            self.plot_data['time'].append(current_time)
            self.plot_data['adc_values'].append(new_adc_value)
            self.plot_widget.clear()
            self.plot_widget.plot(self.plot_data['time'], self.plot_data['adc_values'])
            
            line1 = pg.InfiniteLine(pos=64910, angle=0, pen=pg.mkPen('r', width=2))
            line2 = pg.InfiniteLine(pos=64960, angle=0, pen=pg.mkPen('r', width=2))
            self.plot_widget.addItem(line1)
            self.plot_widget.addItem(line2)


            # Actualizare BCD Display în funcție de valoarea primită
            if 64800 < new_adc_value <= 64910:
                self.bcd_display_label.setText("2")
            elif 64911 <= new_adc_value <= 64960:
                self.bcd_display_label.setText("5")
            elif new_adc_value >= 64961:
                self.bcd_display_label.setText("8")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWin = MainWindow()
    mainWin.show()
    sys.exit(app.exec())
