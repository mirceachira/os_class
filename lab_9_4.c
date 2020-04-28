// Fie Pi procesul ce verifica dacă i este un divizor pentru N dat și determină ordinul de multiplicitate al acestui divizor. Lansând în execuție o structură adecvata de astfel de procese, să se descompună în factori primi numarul N dat.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int isPrime(int n) {
    if (n == 2) {
        return 1; 
    } else if (n <= 1) {
        return 0;
    }

    for(int i=2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
          return 0;
      }
  }

  return 1;
}


int main()
{
    int n = 100;

    printf("The number is %d\n", n);
    for (int i=0; i<=n; i++) {
        if (isPrime(i)) {
            int id = fork();
            if (id > 0) {
                if (n % i != 0) return 0;

                int mu = 0;  // multiplicity order
                while (n%i == 0) {
                    mu += 1;
                    n /= i;
                }
                printf("\t%d ^ %d\n", i, mu);
                return 0;
            }
        }
    }

    return 0;
}