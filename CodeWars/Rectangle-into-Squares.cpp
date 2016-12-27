// 6 kyu: Rectangle into Squares
// Url: https://www.codewars.com/kata/55466989aeecab5aac00003e
#include <vector>

class SqInRect
{
  public:
  static std::vector<int> sqInRect(int lng, int wdth);
};

std::vector<int> SqInRect::sqInRect(int lng, int wdth) {
    if (lng==wdth) return {};

    std::vector<int> container;
    int a = std::max(lng, wdth);
    int b = std::min(lng, wdth);

    while((a!=1||b!=1)&&a!=b) {
        container.push_back(b);
        int temp = a - b;
        a = std::max(temp, b);
        b = std::min(temp, b);
    }
    container.push_back(a);
    return container;
}
