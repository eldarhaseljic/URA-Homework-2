#include <iostream>

int main(int argc, char *argv[])
{
  int v[] { 7, 18, 52, 20, 22, 46, 51, 17, 88 };
  auto velicina = sizeof(v)/sizeof(*v);
  int brojac=1;
  std::cout << std::endl;
  std::cout << "Elementi niza prije sorta " << std::endl;
  for(auto el: v)
  {
    std::cout << el << "\t" ;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  for(auto i=1;i<velicina;++i)
  {
    for(auto j = 0; j<velicina-i;++j)
    {
      if(v[j+1]<v[j])
      {
        auto tmp = v[j];
        v[j] = v[j+1];
        v[j+1]= tmp;
        std::cout << std::string(70,'-') << std::endl;
        std::cout << brojac << ". zamjena(iteracija) << swap(";
        std::cout << v[j+1] << "," <<v[j] << ")" << std::endl;
        std::cout << std::string(70,'-') << std::endl; 
          for(auto el:v)
            {
              std::cout << el << "\t";
            }
          brojac++;
        std::cout << std::endl;
      }
    }
  }
  std::cout << std::endl;
  std::cout << "Elementi niza poslje sorta " << std::endl;
    for(auto el: v)
      {
        std::cout << el << "\t" ;
      }
    std::cout << std::endl;
  return 0;
}
