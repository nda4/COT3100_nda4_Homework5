#include <iostream>
#include <random>
#include <math.h>

/*
    ***IN THE TERMINAL TYPE "make" AND THE PROGRAM WILL RUN***

    I am definitely doing something wrong...but i am not sure what.
    It works just fine for most values. But for the values provided in
    the homework i am recieving a negative value and i simply cannot figure
    out why. My guess it has something to do with larbe values but I am not sure.
*/


long findPrivate(long p, long phi_n, long l);
long lcm(long a, long b);
long generatePrime(long n);
bool isPrime(long n);
long gcd(long a, long b);


int main(){
    long n, e, p, q, phi_e;                                       
long d;                                                                
    long encrypted_sentence;

    std::cout << "Please enter the n value: ";
    std::cin >> n;
    std::cout << "Please enter the e value: ";
    std::cin >> e;

    p = generatePrime(n);
    q = n/p;
    long l = lcm(p - 1, q - 1);
    phi_e = (p-1)*(q-1);

    d = findPrivate(e, phi_e, l);
    std::cout << "\nPublic Key: {" << e << "," << n << "}\nPrivate Key: {" << d << "," << n << "}\n\n"; 
    
    std::cout << "\n\nPlease type in the value encrypted with the Public Key: ";
    std::cin >> encrypted_sentence;

    long decrypted_sentence = (long)pow(encrypted_sentence, d)%n; 
    std::cout << "Unencrypted Value: " << decrypted_sentence << std::endl;
    return 0;
}

//Returns d (the private key)
long findPrivate(long e, long phi_e, long l){
    for(long i = 1; i < phi_e; i++){
        if((e*i) % l == 1 % l){
            return i;
        }
    }
    return 0;
}



// Gives a random prime number between given range
long generatePrime(long n){
    for(long i = 2; i <= n; i++){
        if(n % i == 0 && isPrime(i))
            return i;
        }
    return 1;
}

//Returns bool true if num is prime, false if not
bool isPrime(long n) {
   long i, flag = 0;
   for(i=2; i<=n/2; ++i) {
      if(n % i==0) {
         flag=1;
         break;
      }
   }
    if (flag==0)
        return true;
    else
        return false;
}

long gcd(long a, long b) {
   long t;
   while(t != 0) {
        t= a % b;
        if(t==0)
            return b;
        a = b;
        b= t;
   }
   return 0;
}

long lcm(long a, long b){
    long max = 1;
    do
    {
        if (max % a == 0 && max % b == 0)
        {
            return max;
            break;
        }
        else
            ++max;
    } while (true);
}