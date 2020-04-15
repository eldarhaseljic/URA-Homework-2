#include <iostream>
#include <vector>

class Tim {
public:
  std::string naziv{" "};
  int bodovi{0};
  int primljeniGolovi{0};
  int postignutiGolovi{0};
};

void po_bodovima(std::vector<Tim>& timovi)
{
  for(auto i=0;i<timovi.size();++i)
  {
  for(auto j = i;j>0; --j)
    {
      if(timovi[j].bodovi<timovi[j-1].bodovi)
      {
        auto tmp = timovi[j-1];
        timovi[j-1]=timovi[j];
        timovi[j]=tmp;
      }else break;
    }
  }
}

void po_razlici(std::vector<Tim>& timovi)
{
  for(auto i = 0; i<timovi.size(); ++i)
  {
    for(auto j = i; j>0; --j) 
    {
      if(timovi[j].bodovi==timovi[j-1].bodovi)
      {
        auto razlika1 = timovi[j].postignutiGolovi - timovi[j].primljeniGolovi;
        auto razlika0 = timovi[j-1].postignutiGolovi - timovi[j-1].primljeniGolovi;
        if(razlika0<razlika1)
        {
          auto tmp = timovi[j-1];
          timovi[j-1] = timovi[j];
          timovi[j] = tmp;
        }
      }else break;
    }
  }
}
void ista_gol_razlika(std::vector<Tim>& timovi)
{
  for(auto i = 0; i<timovi.size(); ++i)
  {
    for(auto j = i; j>0; --j) 
    {
      if(timovi[j].bodovi==timovi[j-1].bodovi){
      auto razlika1 = timovi[j].postignutiGolovi - timovi[j].primljeniGolovi;
      auto razlika2 = timovi[j-1].postignutiGolovi - timovi[j-1].primljeniGolovi;
      if(razlika1==razlika2)
        {
          if(timovi[j-1].postignutiGolovi<timovi[j].postignutiGolovi)
            {
              auto tmp = timovi[j-1];
              timovi[j-1] = timovi[j];
              timovi[j]=tmp;
            }
        }
    }
  }
}
}
void ostalo(std::vector<Tim>& timovi)
{
  for(auto i=0;i<timovi.size();++i)
  {
    for(auto j=i;j>0;--j)
    {
      if(timovi[j].naziv<timovi[j-1].naziv)
        {
          auto tmp = timovi[j-1];
          timovi[j-1]=timovi[j];
          timovi[j]=tmp;
        }
    } 
  }
}
 
void in_place(std::vector<Tim>& timovi)
{
  ostalo(timovi);
  ista_gol_razlika(timovi);
  po_razlici(timovi);
  po_bodovima(timovi);

  //Program je rastavljen na manje dijelove radi preglednosti 
  //Prvo se svi timovi sortiraju po abecednom redu
  //Nakon toga timovi sa istom gol razlikom se sortiraju po 
  //tako da tim sa vecim brojem postignutih golova ima prednost
  //Nakon toga timovi sa istim brojem bodova se stortiraju tako
  //da tim sa vecom gol razlikom ima prednost
  //Na kraju se timovi sotriraju po bodovima u rastucem redoslijedu
}

  
int main(int argc, char *argv[])
{
  std::vector<Tim> timovi;
  std::cout << std::endl;
  std::cout << " Unesite timove za tabelu " << std::endl;
  bool work = true;
  while(work)
  { 
    Tim temp;
    std::cout << std::string(50,'-') << std::endl;
    std::cout << "Unesite naziv kluba: ";
    getline(std::cin,temp.naziv);
    std::cout << "Unesite broj bodova: ";
    while(!(std::cin >> temp.bodovi))
    {
      std::cin.clear();
      std::cin.ignore();
    }
    std::cout << "Unesite broj primljenih golova: ";
    while(!(std::cin >> temp.primljeniGolovi))
    {
      std::cin.clear();
      std::cin.ignore();
    }
    std::cout << "Unesite broj postignutih golova: ";
    while(!(std::cin >> temp.postignutiGolovi))
    {
      std::cin.clear();
      std::cin.ignore();
    }
    timovi.push_back(temp);
    std::cout << std::string(50,'-') << std::endl;
    bool tmp = true;
    while(tmp)
    { 
      std::cout << std::endl;
      std::cout << "Zelite li nastaviti sa unosom klubova(Y/n) ";
      std::string odluka;
      std::cin >> odluka;
      if(odluka!="y" || odluka!="Y" || odluka!="n" || odluka!="N"){tmp=true;}
      
      if(odluka=="y" || odluka =="Y") { work=true; tmp=false; }
      else {  if(odluka=="n" || odluka=="N") {  work = false; tmp=false;  } }
    }
    std::cin.ignore();
    std::cout << std::endl;
  }
  in_place(timovi);
  std::string prvi = "Naziv tima "+ std::string(2,' ');
  std::string drugi = "Postignuti golovi "+ std::string(2,' ');
  std::string treci = "Primljeni golovi "+ std::string(2,' ');
  std::string cetvrti = "Bodovi "+ std::string(2,' ');
  std::cout << prvi << " | ";
  std::cout << drugi << " | ";
  std::cout << treci  << " | ";
  std::cout << cetvrti  << " |" << std::endl;
  auto sz = prvi.size()+ drugi.size()+ treci.size()+ cetvrti.size()+11;
  std::cout << std::string(sz,'-') << std::endl;
  for(auto el:timovi)
  { 
  auto x = el.naziv.size();
  std::string prazno(prvi.size()-x,' ');
  auto y = std::to_string(el.postignutiGolovi);
  std::string prazno2(drugi.size()-y.size(),' ');
  auto z = std::to_string(el.primljeniGolovi);
  std::string prazno3(treci.size()-z.size(),' ');
  auto b= std::to_string(el.bodovi);
  std::string prazno4(cetvrti.size()-b.size(),' '); 
  std::cout << el.naziv << prazno << " | ";
  std::cout << el.postignutiGolovi << prazno2 << " | ";
  std::cout << el.primljeniGolovi << prazno3 << " | ";
  std::cout << el.bodovi << prazno4 << " |" << std::endl;
  std::cout << std::string(sz,'-') << std::endl;
  }
  return 0;
}
