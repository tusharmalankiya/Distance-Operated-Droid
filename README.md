# Distance Operated Droid

This project features a versatile robot controlled wirelessly via Bluetooth communication. The robot employs an Atmega32 microcontroller, an L293D motor driver, an HC06 Bluetooth module, and an LCD display for real-time command feedback. With the use of the USART protocol, the microcontroller communicates wirelessly with the Bluetooth module, allowing users to send commands remotely. The robot's motors are controlled by the microcontroller based on the commands received, enabling it to perform various tasks according to user inputs.

## Schematic
![img](https://github.com/tusharmalankiya/Distance-Operated-Droid/assets/85736626/770dbe5b-69b0-4cc8-9a5e-69fc7b6a1374)


## Features

- **Bluetooth Control**: Wirelessly control the robot using any Bluetooth-enabled device.
- **Real-time Command Feedback**: The LCD display provides real-time feedback on the commands received, enhancing user interaction and control.
- **Versatile Functionality**: Control the robot to perform various tasks, such as movement, navigation, or manipulation, based on the commands received.
- **Modular Design**: Built with a modular architecture, allowing for easy integration of additional sensors or functionalities for future enhancements.
- **Simple Operation**: Enjoy an intuitive control interface, making it suitable for users of all skill levels.

## Getting Started

To get started, follow these steps:

1. **Setup**: Connect and configure the Atmega32 microcontroller, L293D motor driver, HC06 Bluetooth module, and LCD display according to the provided hardware diagram.
2. **Upload Code**: Load the provided firmware with the `.hex` extension in direcory `Atmel`>`Debug` directory to the Atmega32 microcontroller using your preferred tool, such as **extreamBurner**.
3. **Pair Bluetooth Module**: Pair the HC06 Bluetooth module with your Bluetooth-enabled device.
4. **Control**: Send commands from your Bluetooth-enabled device to control the robot wirelessly.
5. **Monitor**: Observe real-time command feedback on the LCD display to verify successful communication and control.

## Contributions

Contributions to this project are welcome! If you have any ideas for improvements, enhancements, or new features, feel free to open an issue or submit a pull request.

## License

This project is licensed under the GNU General Public License (GPL) version 3.0. By accessing or using this project, you agree to comply with the terms and conditions outlined in the [LICENSE](LICENSE) file.

