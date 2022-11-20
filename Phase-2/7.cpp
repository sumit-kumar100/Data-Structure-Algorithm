/*
int first = 8;
int second = 18;
int *ptr = &second;
*ptr = 9;
cout  << first << " " << second << endl;    

OUTPUT : 8 9

======================================================================

int first = 6;
int *p = &first;
int *q = p;
(*q)++;
cout << first  << endl;

OUTPUT : 7

======================================================================

int first = 8;
int *p = &first;
cout << (*p)++ << " ";
cout << first << endl;

OUTPUT : 8 9

======================================================================

int *p = 0;
int first = 110;
*p = first;
cout << *p << endl;

OUTPUT : ERROR

======================================================================

int first = 8;
int second = 11;
int *third = &second; 
first = *third;
*third = *third + 2;
cout  << first << "  " << second << endl;

OUTPUT : 11 13

======================================================================

float f = 12.5;
float p = 21.5;
float* ptr = &f;
(*ptr)++;
*ptr = p;
cout << *ptr << " " << f << " " << p << endl;

OUTPUT : 21.5 21.5 21.5

======================================================================


int arr[5];
int *ptr;
cout << sizeof(arr) << " " << sizeof(ptr) << endl;

OUTPUT : 20 8

======================================================================


int arr[] = {11, 21, 13, 14};
cout << *(arr) << " " << *(arr+1) << endl;

OUTPUT : 11 21

======================================================================


int arr[6] = {11, 12, 31};
cout << arr << " " << &arr << endl;

OUTPUT : 0x5bad3ff710 0x5bad3ff710

======================================================================


int arr[6] = {11, 21, 13};
cout << (arr + 1) << endl;

OUTPUT : 0xb4007ffbf4 that is address of 21

======================================================================


int arr[6] = {11, 21, 31};
int *p = arr;
cout << p[2] << endl;

OUTPUT : 31

======================================================================

int arr[] = {11, 12, 13, 14, 15};
cout << *(arr) << " " << *(arr + 3);

OUTPUT : 11 14

======================================================================


int arr[] = {11, 21, 31, 41};
int *ptr = arr++;
cout << *ptr << endl;

OUTPUT : ERROR as arr = arr + 1 is not allowed as we are trying to make change in the name of symbol table

======================================================================


char ch = 'a';
char* ptr = &ch;
ch++;
cout << *ptr << endl;

OUTPUT : b

======================================================================

char arr[] = "abcde";
char *p = &arr[0];
cout << p << endl;

OUTPUT : abcde

======================================================================

char arr[] = "abcde";
char *p = &arr[0];
p++;
cout << p << endl;   

OUTPUT : bcde ,Here we are shifting the pointer to the next charcter p++  =  p += 1

======================================================================

char str[]= "babbar";
char *p = str;
cout << str[0] << " " << p[0] << endl;

OUTPUT : b b 

======================================================================

void update(int *p){
    *p = (*p)  *  2;
}

int main(){
    int i = 10;
    update(&i);
    cout << i << endl;
}

OUTPUT : 20

======================================================================

void fun(int arr[]) {
    cout << arr[0] << " ";
}

int main() {
    int arr[] = {11, 12, 13, 14};
    fun(arr + 1);
    cout << arr[0] << endl;
}

OUTPUT : 12 11  IMPORTANT BECAUSE OF PASS BY VALUE

======================================================================

void update(int *p){
    int a = 70;
    p = &a;
    *p = (*p) * (*p);
}

int main(){
    int a = 70;
    update(&a);
    cout << a << endl;
}


OUTPUT : 70 AS NO CHANGE IN ORIGINAL ADDRESS VALUE IMPORTANT BECAUSE OF PASS BY VALUE.

======================================================================

int first = 110;
int *p = &first;
int **q = &p;
int second = (**q)++ + 9;
cout << first << " " << second << endl; 

OUTPUT : 111 119

======================================================================

int first = 100;
int *p = &first;
int **q = &p;
int second = ++(**q);
int *r = *q;
++(*r);
cout << first << " " << second << endl; 

OUTPUT : 102 101

======================================================================

void increment(int **p){
    ++(**p);
}

int main(){
    int num = 110;
    int *ptr = &num;
    increment(&ptr);
    cout << num << endl;
}  

OUTPUT : 111 AS WE ARE PASSING ADDRESS OF POINTER *p WILL GIVE THE ADDRESS OF NUM **p WILL GIVE VALUE AT ADDRESS *P WHICH IS ADDRESS OF NUM

======================================================================

int arr[] = {41, 52, 36, 74};
int *p = (arr + 1);
cout << *arr + 8;

OUTPUT : 49

======================================================================

char *p; 
char str[] = "pqrstuv";
p = str;
p += 3;
cout << p;

OUTPUT : stuv

======================================================================

char arr[20];
int i;
for(i = 0; i < 10; i++) {
    *(arr + i) = 65 + i;
}
*(arr + i) = '\0';
cout << arr;

OUTPUT : ABCDEFGHIJ

======================================================================

float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
float *ptr1 = &arr[0];
float *ptr2 = ptr1 + 3;
cout<<*ptr2<<" ";
cout<< ptr2 - ptr1;  

OUTPUT : 90.5 3 , Here 3 is (ptr2 - ptr1) that is we are not subtracting the address hence we are subtracting the difference between two address.

======================================================================

char st[] = "ABCD";
for(int i = 0; st[i] != ‘\0’; i++) {
    cout << st[i] << *(st)+i << *(i+st) << i[st];
}

OUTPUT : 
A 65 A A 
B 66 B B
C 67 C C 
D 68 D D

======================================================================

void Q(int z)
{
    z += z;
    cout << z << " ";
}

void P(int *y) 
{
    int x = *y + 2;
    Q(x);
    *y = x - 1; 
    cout << x << " ";
}

int main()
{
    int x = 5;
    P(&x);
    cout << x;
    return 0;
}


OUTPUT : 14 7 6

======================================================================

int ***r, **q, *p, i=8;
p = &i;
(*p)++;
q = &p;
(**q)++;
r = &q;
cout<<*p << " " <<**q << " "<<***r;

OUTPUT : 10 10 10 

======================================================================

int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}

int main() {
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);
    return 0;
}

OUTPUT : 19 NOTE X PASSED TO THE FUNTION IS COPY NOT REFERENCE OF C VARIABLE

======================================================================


*/