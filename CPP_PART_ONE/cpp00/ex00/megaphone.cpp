#include <iostream>
#include <cctype>
#include <cstdlib>

int main (int ac , char **av)
{
    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl ;
    }

    if (ac >= 2)
    {        
            

         int i = 1;
         while (av[i])
         {     
       
          
            int j = 0;
             while(av[i][j])
            { 
                 av[i][j] = toupper(av[i][j]);
                 std::cout << av[i][j] ;
                 j++;
            }
             j = 0;
              while(av[i][j])
              {
                if(av[i][j] == '\0')
                    break;
                j++;
              }
                if (i < ac - 1 && av[i][0] != '\0')
                    std :: cout << ' ' ;
                i++;
        
    }
        i = 1 ; 
            while (i < ac)
                {
                    if ( av[i][0] != '\0')
                        std :: cout << '\n' ;
                    i++;                       
                     break;

                }
        }
}
