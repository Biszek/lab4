#include <iostream>

using namespace std;

void Wyswietlenie_liczby(int);
int zeraijedynki(int);

int main(int argc, char** argv) {
	
	int a=atoi(argv[1]);
	
	cout<<"k - "<<zeraijedynki(a)<<" "; Wyswietlenie_liczby(zeraijedynki(a)); cout<<endl;
	cout<<"n*k - "<<zeraijedynki(a)*a<<" "; Wyswietlenie_liczby(zeraijedynki(a)*a); cout<<endl;
	
	return 0;
}

void Wyswietlenie_liczby(int a)
{
	string jednosci[] = {"", "jeden ", "dwa ", "trzy ", "cztery ", "piec ", "szesc ", "siedem ", "osiem ", "dziewiec "};
	string nascie[] = {"", "jedenascie ", "dwanascie ", "trzynascie ", "czternascie ", "pietnascie ", "szesnascie ",
			 			"siedemnascie ", "osiemnascie " "dziewietnascie "};
	
	string dziesiatki[] = {"", "dziesiec ", "dwadziescia ", "trzydziesci ", "czterdziesci ", "piecdziesiat ",
					"szescdziesiat ", "siedemdziesiat ", "osiemdziesiat ", "dziewiecdziesiat "};
	
	string setki[] = {"", "sto ", "dwiescie ", "trzysta ", "czterysta ", "piecset ", "szescset ", "siedemset ",
						  "osiemset ", "dziewiecset "};
	
	string tysiace[] = { "", "tysiecy ","tysiace ", "tysiace ", "tysiace ", "tysiecy ", "tysiecy ", "tysiecy ",
						 "tysiecy ","tysiecy ","tysiac "};

	
	if(a==0)
	{
	cout<<"Zero"<<endl;
	a=0;
	}
	
	if(a>1000000)
	{
	cout<<"Liczba jest za duza(0-1000000)"<<endl;
	a=0;
	}

	
	if(a==1000000)
	{
	cout<<"Milion"<<endl;
	a=0;
	}	
	
	
	int tab[6];
	
	for(int i=0;i<6;i++)
	{
	tab[5-i]=a%10;
	a/=10;
	}
		for(int i=0;i<6;i+=3)
		{
		cout<<setki[tab[i]];
		
		if(tab[i+1]>1 || (tab[i+1]==1 && tab[i+2]==0))
		cout<<dziesiatki[tab[i+1]]<<jednosci[tab[i+2]];
		
		else if(tab[1+i]==1 && tab[2+i]!=0)
		cout<<nascie[tab[1+i]];

		else 
		cout<<jednosci[tab[2+i]];
		
		if(tab[2]!=0 && tab[2]!=1)
		cout<<tysiace[tab[2-i]];
		
		else if(i==0 &&(tab[0]!=0 || tab[1]!=0))
		cout<<tysiace[1];
		
		else if(i==0 && tab[2]==1)
		cout<<tysiace[10];
		}
		

}

int zeraijedynki(int n)
{
	if(n == 0 || n == 1)
		return n;

	int k=0;
    while(true) 
    {
        k++;
		int spr= n * k;
        while(spr>0)
        {
            if(spr % 10 != 0 && spr % 10 != 1)		
                break;

            spr/=10;									
            if(spr==1)							
                return k;
        }
    }
}
