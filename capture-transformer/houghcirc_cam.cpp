#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
#define SYSTEM_ERROR (1)

int main() {
    // Open the default video capture device (webcam)
    VideoCapture cam0(0);

    // Check if webcam opened successfully
    if (!cam0.isOpened()) {
       exit(SYSTEM_ERROR);
    }

    Mat frame, gray;
    cam0.set(CAP_PROP_FRAME_WIDTH, 640);
   cam0.set(CAP_PROP_FRAME_HEIGHT, 480);

    while (true) {
        // Capture frame-by-frame from the webcam
         cam0.read(frame);

        // Check if frame is captured successfully
        if (frame.empty()) {
            exit(SYSTEM_ERROR);
            break;
        }

        // Convert frame to grayscale
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Apply median blur to reduce noise
        medianBlur(gray, gray, 5);

        // Detect circles using HoughCircles
        std::vector<Vec3f> circles;
        HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
                     gray.rows/16,  // Adjust this value for circle distance
                     100, 30, 1, 30 // Adjust last two parameters for circle size
        );

        // Draw detected circles on the frame
        for (size_t i = 0; i < circles.size(); i++) {
            Vec3i c = circles[i];
            Point center = Point(c[0], c[1]);
            int radius = c[2];

            // Draw circle center
            circle(frame, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
            // Draw circle outline
            circle(frame, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
        }

        // Display the frame with detected circles
        imshow("Interactive Camera - Circle Detection", frame);

        // Exit loop on 'q' key press
        char c = (char)waitKey(1);
        if (c == 'q') {
            break;
        }
    }

    // Release capture device and destroy windows
  //  cap.release();
    destroyAllWindows();

    return 0;
}
