#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
    int coeff;
    struct term *next;
} term;

term *createPolynomial(int degree)
{
    term *polynomial = NULL, *last, *temp;
    while (degree)
    {
        printf("Enter coefficient of x^%d: ", degree--);
        temp = (term *)malloc(sizeof(term));
        scanf("%d", &temp->coeff);
        if (!polynomial)
            polynomial = last = temp;
        else
            last = last->next = temp;
        temp = NULL;
    }
    printf("Enter constannt term:");
    temp = (term *)malloc(sizeof(term));
    scanf("%d", &temp->coeff);
    if (!polynomial)
        return temp;
    last->next = temp;
    return polynomial;
}

void printPolynomial(term *poly, int deg)
{
    while (deg)
    {
        deg--;
        if (!poly->coeff)
        {
            poly = poly->next;
            continue;
        }
        printf("(%d)x^%d + ", poly->coeff, deg + 1);
        poly = poly->next;
    }

    printf("%d\n", poly->coeff);
}

void addPolynomial(term *poly1, term *poly2, int deg1, int deg2)
{
    while (deg1 > deg2)
    {
        printf("(%d)x^%d + ", poly1->coeff, deg1--);
        poly1 = poly1->next;
    }
    while (deg2 > deg1)
    {
        printf("(%d)x^%d + ", poly2->coeff, deg2--);
        poly2 = poly2->next;
    }
    while (deg1)
    {
        printf("(%d)x^%d + ", poly1->coeff + poly2->coeff, deg1--);
        poly1 = poly1->next;
        poly2 = poly2->next;
    }
    printf("%d\n", poly1->coeff + poly2->coeff);
}

int main()
{
    term *poly1, *poly2;
    int deg;
    printf("Enter degree of polynomials:");
    scanf("%d", &deg);
    printf("Enter coefficients for polynomial 1:\n");
    poly1 = createPolynomial(deg);
    printf("Enter coefficients for polynomial 2:\n");
    poly2 = createPolynomial(deg);
    printf("Poly1:");
    printPolynomial(poly1, deg);
    printf("Poly2:");
    printPolynomial(poly2, deg);
    printf("Poly1 + Poly2:");
    addPolynomial(poly1, poly2, deg, deg);

    return 0;
}