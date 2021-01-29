/*
Code by
Md. Rabiul Islam
ID: 201104
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"****** Welcome to Server Window ******\n\n\n";
    while (true) {
        int primeNumber, primitiveRoot, n;
        cout<<"Enter a prime number greater than 2: ";
        cin>>primeNumber;
        FILE* out = fopen("server.txt", "wb+");

        for (int i = primeNumber - 1; i > 1; i--) {
            n = 0;
            int k = 1;
            map<int, int> mp;
            for (int j = 1; j < primeNumber; j++) {
                k = (k * i) % primeNumber;
                if (mp[k]++)    break;
                n++;
            }
            if (n == primeNumber - 1) {
                primitiveRoot = i;
                break;
            }
        }
        cout<<endl<<endl<<primitiveRoot<<" is used as primitive root of "<<primeNumber<<endl;
        fprintf(out, "%d %d", primeNumber, primitiveRoot);
        cout<<"\nPress 1, to input new prime number.\nPress 2, to exit.\n\n";
        fclose(out);
        bac:;
        int x;
        cin>>x;
        cout<<endl;
        if (x == 2)
            break;
        if (x != 1) {
            cout<<"Wrong press. Please press 1 or 2.\n";
            goto bac;
        }
    }
    return 0;
}

