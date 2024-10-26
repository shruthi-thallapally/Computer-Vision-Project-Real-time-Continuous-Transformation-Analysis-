# Project Overview

This project integrates a **Logitech C2xx camera** with a **Raspberry Pi**, using **OpenCV's VideoCapture** to create an interactive, real-time video processing tool. The tool allows users to dynamically select video resolution and adjust processing thresholds through a trackbar interface, offering flexibility and real-time processing capabilities.

## Key Features

### Interactive Interface
- Developed a **trackbar interface** for easy resolution selection and dynamic threshold adjustments.
- Enhances user experience by allowing custom configurations in real-time.

### Real-Time Image Processing
- Deployed a suite of image transformation algorithms:
  - **Canny Edge Detection**
  - **Hough Line Transformation**
  - **Hough Circle Transformation**
- User-selected settings trigger tailored filtering and transformations on video frames in real-time, enabling responsive and accurate image processing.

### Performance Optimization
- **Precise frame timestamping** and **SCHED_FIFO scheduling** were used to monitor and optimize processing durations.
- Execution times were assessed against predefined deadlines, ensuring performance consistency under real-time constraints.

## Requirements
- **Raspberry Pi** with **Logitech C2xx camera**
- **OpenCV** library installed on the Raspberry Pi

## Usage
1. Connect the Logitech C2xx camera to the Raspberry Pi.
2. Run the application and use the trackbar to adjust resolution and threshold settings.
3. Select desired image processing transformations to apply to video frames in real-time.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
