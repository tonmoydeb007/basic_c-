#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            } else {
                return max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted");
}

int main() {
    int n1, n2;
    cout << "Enter the number of elements in the first array: ";
    cin >> n1;

    vector<int> nums1(n1);
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter the number of elements in the second array: ";
    cin >> n2;

    vector<int> nums2(n2);
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    double result = findMedianSortedArrays(nums1, nums2);
    cout << "The median is " << result << endl;

    return 0;
}
