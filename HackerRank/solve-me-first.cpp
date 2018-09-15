/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solveMeFirst(int a, int b) {
  return a+b;
}

int main() {
  int num1, num2;
  int sum;
  scanf("%d%d",&num1,&num2);
  sum = solveMeFirst(num1,num2);
  printf("%d",sum);
  return 0;
}
