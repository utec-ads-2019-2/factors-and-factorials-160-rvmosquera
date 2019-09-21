#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
                    89, 97};
    int prime_num = 25;
    int factors[25];
    int number, aux;
    int n , j=0;

    for(int i=0; i < prime_num; i++) {
        factors[i] = 0;
    }


    while(scanf("%d", &number)== 1) {
        if(number == 0 ) break;

        n=2;
        while( n <= number ) {
            aux = n;

            j=0;
            while ( aux != 1 ) {
                if ( aux % primes[j] == 0 ) {
                    factors[j]++;
                    aux = aux / primes[j];
                } else {
                    j++;
                }
            }
            n++;
        }
        cout << setw(3)<<number;
        cout << "! =";
        j=0;
        while(primes[j] <= number) {
            cout <<setw(3)<<factors[j];
            factors[j] = 0;
            j++;
            if ( j == prime_num)
                break;

            if ( j%15==0 && primes[j] <= number)
                cout<<"\n      ";
        }
        cout<<endl;
    }

    return EXIT_SUCCESS;
}
