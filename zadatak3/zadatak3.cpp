#include<iostream>
#include<string>

int main(int argc, char *argv[])
{
  int x[]{9, 13, 58, 23, 19, 57, 88, 21, 7 };
  int velicina = sizeof(x)/sizeof(*x);
  std::cout << std::endl;
  std::cout << "Elementi niza prije sorta " << std::endl;
  for(auto el: x)
  {
    std::cout << el << "\t" ;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  int brojac = 1;
  for(int korak=velicina/2; korak>0;korak/=2)
  {
    for(int i=korak; i<velicina ; ++i)
    {
      for(int j=i; j>=korak ;j-=korak)
      {
        if(x[j]<x[j-korak])
        {
          int tmp = x[j-korak];
          x[j-korak]=x[j];
          x[j]=tmp;
          std::cout << std::string(70,'-') << std::endl;
          std::cout << brojac << ". zamjena(iteracija) << swap(";
            std::cout << x[j] << "," <<x[j-korak] << ")" << std::endl;
          std::cout << std::string(70,'-') << std::endl;
          for(auto el:x)
          {
            std::cout << el << "\t";
          }
          brojac++;
          std::cout << std::endl;
        }
      }
    }
  }
  std::cout << std::endl;
  std::cout << "Elementi niza poslje sorta " << std::endl;
  for(auto el: x)
  {
    std::cout << el << "\t" ;
  }
  std::cout << std::endl;
 return 0;
}
