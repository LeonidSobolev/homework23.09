#include <iostream>

int main(){
  double matrix[100][100];
  double roots[100];
  //memset(matrix, 0, 10000);
  int n;
  std::cout << "введите количество уравнений" << std::endl;
  std::cin >> n;
  std::cout << "введите коэффиценты" << std::endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= n; j++){
      std::cin >> matrix[j][i];
    }
  }



  for(int i = 0; i < n; i++){
        double max = matrix[i][i];
        int max_ind = i;

        for(int j = i; j < n; j++){
          if(matrix[i][j] > max){
            max = matrix[i][j];         // ищем максимум
            max_ind = j;
          }
        }

        for(int h = 0; h <= n; h++){
          double tmp;
          tmp = matrix[h][i];
          matrix[h][i] = matrix[h][max_ind];      //перестановка строк в матрице
          matrix[h][max_ind] = tmp;
        }

    for(int j = i; j <= n; j++){
      double a = matrix[i][j];
      for(int h = i; h <= n; h++) matrix[h][j] = matrix[h][j] / a;  //приводим по i-тому коэффиценту
    }

    for(int j = i + 1; j < n; j++){
      for(int h = 0; h <= n; h++) matrix[h][j] = matrix[h][j] - matrix[h][i];
    }


  }

  for(int i = n - 1; i >= 0; i--){
    double rt = 0.0;
    for(int j = 0; j < n; j++){
      if (j == i) continue;
      rt += matrix[j][i]*roots[j];
    }
    roots[i] = matrix[n][i] - rt;
  }

  for(int i = 0; i < n; i++) std::cout << roots[i] << " ";

  /*for(int i = 0; i < n; i++){
    for(int j = 0; j <= n; j++){
      std::cout << matrix[j][i] << " ";
    }
    std::cout << std::endl;
  }*/

  return 0;
}
