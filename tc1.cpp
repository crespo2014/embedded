class D
{
private:
 static int c;
 static int* pc;
};

int D::c = 9;
int* D::pc = &D::c;
int main()
{
D d;
return 0;
}
