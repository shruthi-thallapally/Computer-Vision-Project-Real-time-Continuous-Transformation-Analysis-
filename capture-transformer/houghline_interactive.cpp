#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

int main() {
    // Open the default video capture device (webcam)
    VideoCapture cap(0);

    // Check if webcam opened successfully
    if (!cap.isOpened()) {
        cerr << "Error opening video capture device!" << endl;
        return -1;
    }

    Mat frame;

    while (true) {
        // Capture frame-by-frame from the webcam
        cap >> frame;

        // Check if frame is captured successfully
        if (frame.empty()) {
            cerr << "Error capturing frame!" << endl;
            break;
        }

        // Convert frame to grayscale for Hough Line Transform
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Apply Canny edge detection
        Mat dst;
        Canny(gray, dst, 80, 240, 3); // Adjust thresholds as needed

        // Probabilistic Line Transform (more robust for noisy environments)
        vector<Vec4i> linesP;
        HoughLinesP(dst, linesP, 1, CV_PI/180, 50, 50, 10); // Adjust parameters for better results

        // Draw detected lines on the frame
        for (size_t i = 0; i < linesP.size(); i++) {
            Vec4i l = linesP[i];
            line(frame, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
        }

        // Display the frame with detected lines
        imshow("Interactive Camera - Hough Lines Transform", frame);

        // Exit loop on 'q' key press
        char c = (char)waitKey(1);
        if (c == 'q') {
            break;
        }
    }

    // Release capture device and destroy windows
    cap.release();
    destroyAllWindows();

    return 0;
}
