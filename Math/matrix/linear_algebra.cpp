#include <iostream>
using namespace std;

// int matrix[3][4] = {
//     {1, 2, 3, 4},  // 第一行
//     {5, 6, 7, 8},  // 第二行
//     {9, 10, 11, 12}  // 第三行
// };

#include <vector>

class Matrix {
private:
    int rows;  // 矩阵的行数
    int cols;  // 矩阵的列数

    std::vector< std::vector<int> > data;  // 矩阵的数据

public:
    // 构造函数
    Matrix(int rows, int cols) : rows(rows), cols(cols) {

        data.resize(rows, std::vector<int>(cols)); //初始化或调整二维向量的大小
        //;将data的大小改为rows，并将新添加的元素初始化为大小为cols的向量
        //这样，data就成为了一个rows行cols列的二维向量，可以用来表示一个rows行cols列的矩阵。
    }

        //std::vector是C++的一个动态数组类，提供了许多方便的功能，如自动管理内存。
        // data是一个二维向量，外层向量的大小是rows，表示矩阵的行数。内层向量的大小是cols，表示矩阵的列数。
        // resize是std::vector的一个方法，用于改变向量的大小。
        // 如果新的大小大于原来的大小，那么新的元素将被添加到向量的末尾，并用给定的值初始化。
        // 如果新的大小小于原来的大小，那么超出的元素将被删除。
        

    // 获取矩阵的行数
    int getRows() const {
        return rows;
    }

    // 获取矩阵的列数
    int getCols() const {
        return cols;
    }

    // 设置矩阵的某个元素的值
    void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    // 获取矩阵的某个元素的值
    int getElement(int row, int col) const {
        return data[row][col];
    }

        // 打印矩阵的内容
    void printMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    Matrix m(3, 4);  // 创建一个3行4列的矩阵

    // 用一些数据填充矩阵
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            m.setElement(i, j, i * m.getCols() + j);
        }
    }

    return 0;
}