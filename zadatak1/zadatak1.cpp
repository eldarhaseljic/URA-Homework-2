#include<iostream>
#include<vector>
#include<cstdio>
bool sekvencijalno(const std::vector<long>& v , long br)
{
  //Kod sekvencijalnog pretrazivanja nije potrebno da bude vektor sortiran
  for(auto it=v.begin(); it!=v.end();++it)
  {
    if(*it == br) return true;
  }
  return false;
}
bool binarno(std::vector<long>& v , long br)
{
  //Kod binarnog pretrazivanja potrebno je da vetor bude sortiran 
  //kao vrstu sortiranja koristicemo insertion sort 
  //kao jedan od brzih nacina sortiranja
  for(auto i=0; i<v.size();++i)
  {
    for(auto j=i; j>0;--j)
    {
      if(v[j]<v[j-1])
      {
        auto tmp = v[j-1];
        v[j-1]=v[j];
        v[j]=tmp;
      }
    }
  }
  auto low = 0;
  auto high = v.size()-1;
  while(low<=high)
  {
    auto mid = (low+high)/2;
    if(v[mid]<br)
    {
      low = mid+1;
    }
    else if(v[mid]>br)
    {
      high=mid-1;
    }
    else
    {
      return true;
    }

  }
  return false;
}

int main(int argc, char *argv[])
{
  long num;
  std::vector<long> brojevi;
  bool work = true;
  while(work)
  {
    std::cout << std::string(50,'-') << std::endl;
    std::cout << "Za unos podataka unesite " << "\t\t" << "1" << std::endl;
    std::cout << "Za ispis podataka unesite " <<  "\t\t" << "2" << std::endl;
    std::cout << "Za pretrazivanje unesite " << "\t\t" << "3" << std::endl;
    std::cout << "Za izlaz unesite " << "\t\t\t" << "0" <<std::endl;
    std::cout << std::string(50,'-') << std::endl;
    std::cout << "Vas izbor je: ";
    int izbor;
    while(!(std::cin >> izbor))
    {
      std::cin.clear();
      std::cin.ignore();
    }
    if(izbor==1)
        {
          std::cout << std::string(50,'-') << std::endl;
          std::cout << "Unesite proizvoljan broj prirodnih brojeva u vektor " << std::endl;
          std::cout << "Unesite bilo koji karakter za kraj unosa" << std::endl;
          while(true)
              {
                if(!(std::cin >> num))break;
                brojevi.push_back(num);
                std::cin.clear();
                std::cin.ignore();
              }
        }
    if(izbor== 2)
        {
          std::cout << std::string(50,'-') << std::endl;
          if(brojevi.size()==0)
          {
            std::cout << "Vektor je prazan" << std::endl;
            work = true;
          }
          else
          {
          std::cout << "Elemneti vektora su " << std::endl;
          for(auto el: brojevi)
          {
            std::cout << el  << "\t";
          }
          std::cout  << std::endl;
          std::cout << std::string(50,'-') << std::endl;
          }
        }
      if(izbor== 3)
        {
        std::cout<< std::string(50,'-')<< std::endl;
        if(brojevi.size()==0)
        {
            std::cout << "Vektor je prazan" << std::endl;
            work = true;
        }
        else
        {
          std::cout << "Koju vrstu pretrazivanja zelite"  << std::endl;
          std::cout << "Sekvencijalno "<<"\t\t\t\t" << "1" << std::endl;
          std::cout << "Binarno " << "\t\t\t\t"<< "2" << std::endl;
          std::cout << "Za izlaz iz pretrazivanja " << "\t\t" << "0"<< std::endl;
          std::cout << std::string(50,'-') << std::endl;
          int izbor2;
          std::cout << "Vas izbor je: " ;
          bool tmp=true;
          while(tmp)
          {
          while(!(std::cin>>izbor2))
          {
           std::cin.clear();
           std::cin.ignore();
          }
          if(izbor2==1)
              {
                std::cout << "Koji broj trazite: ";
                long broj;
                std::cin >> broj;
                auto ima_nema = sekvencijalno(brojevi, broj);
                if(ima_nema == true)
                {
                  std::cout << "Broj "<< broj << " se nalazi u vekoru" << std::endl;
                }
                if(ima_nema == false)
                {
                  std::cout << "Broj " << broj << " se ne nalazi u vektoru"<< std::endl;
                }
                std::cout << std::string(50,'-') << std::endl;
              tmp=false;
              }
            if(izbor2==2)
              {
                std::cout << "Koji broj: ";
                long broj;
                std::cin >> broj;
                auto temp = brojevi;
                auto ima_nema = binarno(temp, broj);
                if(ima_nema == true)
                {
                  std::cout << "Broj "<< broj << " se nalazi u vekoru" << std::endl;
                }
                if(ima_nema == false)
                {
                  std::cout << "Broj " << broj << " se ne nalazi u vektoru"<< std::endl;
                }
                std::cout << std::string(50,'-') << std::endl;
              tmp=false;
              }
            if(izbor2==0) tmp=false;
          }
          }
        }
    if (izbor== 0){work = false;};
    }
  return 0;
}
