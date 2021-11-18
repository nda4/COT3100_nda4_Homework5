#include <iostream>
#include <random>
#include <math.h>

/*
    ***IN THE TERMINAL TYPE "make" AND THE PROGRAME WILL RUN***

    I wrote prime generator cause im dumb and thought i would need to...zzz
*/


int findPrivate(int p, int q);
int generatePrime();
bool isPrime(int n);

int main(){
    int n, e, d;
    std::string encrypted_sentence;

    std::cout << "Please enter the n value: ";
    std::cin >> n;
    std::cout << "Please enter the e value: ";
    std::cin >> e;
    d = findPrivate(e, n);
    std::cout << "\nPublic Key: {" << e << "," << n << "}\nPrivate Key: {" << d << "," << n << "}"; 
    
    std::cout << "\n\nPlease type in the value encrypted with the Public Key: ";
    std::cin >> encrypted_sentence;

    for(int i = 0; i > encrypted_sentence.size(); i++){
        encrypted_sentence.at(i) =  fmod(pow(encrypted_sentence.at(i), e), (float)n);
    }

    std::cout << encrypted_sentence << std::endl;
}

//Returns d (the private key)
int findPrivate(int e, int n){
    float d = (((float)n*1) + 1)/(float)e;
    int i = 1;
    while((fmod(d, 1.0)) != 0){
        i++;
        d =(((float)n*(float)i) + 1.0)/(float)e;
    }
    return d;
}

// Gives a random prime number between given range
int generatePrime(){
    int current_number = 2;
    int current_prime = current_number;
    while(current_number <= (rand() % 8011 + 997)){
        current_number++;
        if(isPrime(current_number))
            current_prime = current_number;
    }
    return current_prime;
}
//Returns bool true if num is prime, false if not
bool isPrime(int n) {
   int i, flag = 0;
   for(i=2; i<=n/2; ++i) {
      if(n%i==0) {
         flag=1;
         break;
      }
   }
    if (flag==0)
        return true;
    else
        return false;
}
