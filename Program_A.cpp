/*
Code by
Md. Rabiul Islam
ID: 201104
*/

#include<bits/stdc++.h>
using namespace std;

int pow(int n, int m, int mod)
{
    int k = n;
    while (--m)
        k *= n, k %= mod;
    return k;
}

int main()
{
    cout << "****** Welcome to User A's Window ******\n\n\n";
    while (true) {

        cout<<"\nPress 1, to continue.\nPress 2, to exit.\n";
        int x;
        cin>>x;
        cout<<endl;
        if (x == 2)
            break;
        if (x != 1) {
            cout<<"Wrong press. Please press 1 or 2.\n";
            continue;
        }

        int primeNumber, primitiveRoot, secretKey, publicA, publicB, symmetricKey;

        FILE* inp = fopen("server.txt", "rb");

        fscanf(inp, "%d %d", &primeNumber, &primitiveRoot);

        secretKey = (rand() + time(NULL)) % primeNumber;
        publicA = pow(primitiveRoot, secretKey, primeNumber);
        cout << "A's public key is: " << publicA << endl << "Please input B's public key: ";
        cin >> publicB;
        symmetricKey = pow(publicB, secretKey, primeNumber);
        cout << "Computed symmetric key: " << symmetricKey << endl << endl;
        fclose(inp);
    }
    return 0;
}
