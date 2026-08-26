#define SKY  "*********************"

enum operation{ADD = 1,SUB,MUL,DIV,VAR,QUIT};

int menu(void);

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
long double div(double a, double b);
long double var(const double a[] ,int b,long double *c,long double *d);

int getvar(double a[]);
void getadd(double *a,double *b);
void getsub(double *a,double *b);
void getmul(double *a,double *b);
void getdiv(double *a,double *b);

void clear(void);
double get(void);
void put(long double a,long double b);