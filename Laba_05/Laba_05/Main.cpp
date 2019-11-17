/*
 * Знайти і підключити до проекту сторонню бібліотеку для роботи з зображеннями. 
 * Зчитати деяке зображення та: повернути його на 90 градусів за годинниковою стрілкою і зберегти; 
 * Знайти середнє значення кольору всіх пікселів зображення.
*/

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


void Rotate(std::string path);
cv::Vec3b GetAveragePixel(std::string path);
std::string GetExt(std::string path);

int main()
{
    std::string path;
    std::getline(std::cin, path);
    Rotate(path);
    //auto pixel = GetAveragePixel(path);
    //std::cout << "Average color: " << (int)pixel[2] << " " << (int)pixel[1] << " " << (int)pixel[0] << std::endl;
    system("pause");
}

void Rotate(std::string path)
{
    
    cv::Mat src = cv::imread(path, cv::IMREAD_UNCHANGED);

    cv::Point2f center((src.cols - 1) / 2.0, (src.rows - 1) / 2.0);
    cv::Mat rot = cv::getRotationMatrix2D(center, -90, 1.0);

    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), src.size(), -90).boundingRect2f();

    rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
    rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;

    cv::Mat dst;
    cv::warpAffine(src, dst, rot, bbox.size());

    cv::imwrite(path + "_R_." + GetExt(path), dst);
}

cv::Vec3b GetAveragePixel(std::string path)
{
    auto shit = cv::String(path);
    auto mat = cv::imread(shit, cv::IMREAD_COLOR);
    std::vector<cv::Vec3d> colors;
    for (int i = 0; i < mat.rows; i++)
    {
        colors.push_back(cv::Vec3d());
        for (int j = 0; j < mat.cols; j++)
        {
            auto pixMat = mat.at<cv::Vec3b>(i, j); 
            for (int l = 0; l < 3; l++) colors[i][l] += pixMat[l];
        }
        for (int l = 0; l < 3; l++) colors[i][l] /= mat.cols;
    }
    cv::Vec3d res = 0;
    for (int i = 0; i < mat.rows; i++)
        for (int l = 0; l < 3; l++) res[l] += colors[i][l];
    for (int l = 0; l < 3; l++) res[l] /= mat.rows;
    return res;
}

std::string GetExt(std::string path)
{
    int pos = -1;
    for (int i = path.length() - 1; i >= 0; i--)
    {
        if (path[i] == '.') pos = i + 1;
    }
    if (pos >= path.length() || pos <= 0) return "";
    return path.substr(pos, path.length() - pos);
}

