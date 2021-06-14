#include "mainwindow.h"
#include "ui_mainwindow.h"

#define M_PI   3.14159265358979323846
#define M_E    2.71828182818281828182


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::suma(const int a, const int b)
{
    int result;
    __asm__ __volatile__(
            "movl %1, %%eax;"
            "movl %2, %%ebx;"
            "addl %%ebx, %%eax;"
            "movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)
    );
    return result;
}

int MainWindow::resta(const int a, const int b)
{
    int result;
    __asm__ __volatile__(
            "movl %1, %%eax;"
            "movl %2, %%ebx;"
            "subl %%ebx,%%eax;"
            "movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)
    );
    return result;

}

int MainWindow::multiplicacion(const int a, const int b)
{
    int result;
    __asm__ __volatile__(
            "movl %1, %%eax;"
            "movl %2, %%ebx;"
            "mul %%ebx;"
            "movl %%eax, %0;" : "=g" (result) :	"g" (a), "g" (b)
    );
    return result;
}

int MainWindow::division(const int a, const int b)
{
    int result;
    __asm__ __volatile__(
            "movl %1, %%eax;"
            "movl %2, %%ebx;"
            "cltd;"
            "div %%ebx;"
            "movl %%eax, %0;" : "=g" (result) :	"g" (a), "g" (b)
    );
    return result;
}

int MainWindow::potencia(const int a, const int b)
{
    int result;
    __asm__ __volatile__(
            "movl %1, %%eax;"
            "movl %1, %%ebx;"
            "movl %2, %%ecx;"
            "cmpl $1, %%ecx;"
            "je UNO;"
            "jl CERO;"
            "decl %%ecx;"
            "POTENCIA: imull %%ebx;"
                "loopl POTENCIA;"
            "jmp FIN;"
            "UNO: jmp FIN;"
            "CERO: movl $1,%%eax;"
                "jmp FIN;"
            "FIN: movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)

    );
    return result;
}

float MainWindow::raiz(const float n) {
    float resultado;
    __asm__ __volatile__ (
            "fld %1;"
            "fsqrt;"
            "fst %0;" : "=m" (resultado) : "g" (n)
    ) ;
    return resultado;
}

float MainWindow::seno(float n)
{
    n = (n*M_PI)/180;
    long double resultado;

    __asm__ __volatile__(
            "fsin" : "=t" (resultado) : "0" (n)
    );
    return resultado;
}

float MainWindow::coseno(float n)
{
    n = (n*M_PI)/180;
    long double resultado;

    __asm__ __volatile__(
            "fcos" : "=t" (resultado) : "0" (n)
    );
    return resultado;
}

int MainWindow::modulo(const int a, const int b)
{
    int result;
    __asm__ __volatile(
            "mov %1, %%eax;"
            "mov %2, %%ebx;"
            "funcion: cmp %%ebx, %%eax;"
            "jl fin;"
            "sub %%ebx, %%eax;"
            "jmp funcion;"
            "fin: movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)

    );
    return result;
}

int MainWindow::factorial(const int n)
{
    int result;
    __asm__ __volatile__(
            "xor %%eax, %%eax;"
            "inc %%eax;"
            "xor %%ebx, %%ebx;"
            "inc %%ebx;"
            "movl %1,%%ecx;"
            "fun: mul %%ebx;"
            "inc %%ebx;"
            "cmp %%ebx,%%ecx;"
            "jne fun;"
            "mul %%ebx;"
            "movl %%eax, %0;" : "=g" (result) : "g" (n)
    );
    return result;
}


int MainWindow::absoluto(const int n)
{
    int result;
    int neg = -1;
    __asm__ __volatile__(
            "mov %1, %%eax;"
            "cmp $0, %%eax;"
            "jg positive;"
            "mov %2, %%ebx;"
            "mul %%ebx;"
            "positive: mov %%eax, %0;" : "=g" (result) : "g" (n), "g" (neg)
    );
    return result;
}


void MainWindow::on_sumaPB_clicked()
{
    ui->operacion1LB->setText("SUMA");
    ui->stackedWidget->setCurrentIndex(1);
    operacion = SUMA;
}


void MainWindow::on_restaPB_clicked()
{
    ui->operacion1LB->setText("RESTA");
    ui->stackedWidget->setCurrentIndex(1);
    operacion = RESTA;
}


void MainWindow::on_multiplicacionPB_clicked()
{
    ui->operacion1LB->setText("MULTIPLICACION");
    ui->stackedWidget->setCurrentIndex(1);
    operacion = MULTIPLICACION;
}


void MainWindow::on_divisionPB_clicked()
{
    ui->operacion1LB->setText("DIVISION");
    ui->stackedWidget->setCurrentIndex(1);
    operacion = DIVISION;
}


void MainWindow::on_potenciaPB_clicked()
{
    ui->operacion1LB->setText("POTENCIA");
    ui->stackedWidget->setCurrentIndex(1);
    operacion = POTENCIA;
}


void MainWindow::on_raizPB_clicked()
{
    ui->operacion2LB->setText("RAIZ");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = RAIZ;
}


void MainWindow::on_senPB_clicked()
{
    ui->operacion2LB->setText("SENO");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = SENO;
}


void MainWindow::on_cosPB_clicked()
{
    ui->operacion2LB->setText("COSENO");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = COSENO;
}


void MainWindow::on_tanPB_clicked()
{
    ui->operacion2LB->setText("TANGENTE");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = TANGENTE;
}

void MainWindow::on_secantePB_clicked()
{
    ui->operacion2LB->setText("SECANTE (deg)");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = SECANTE;
}


void MainWindow::on_cosecantePB_clicked()
{
    ui->operacion2LB->setText("COSECANTE (deg)");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = COSECANTE;
}


void MainWindow::on_cotangentePB_clicked()
{
    ui->operacion2LB->setText("COTANGENTE (deg)");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = COTANGENTE;
}


void MainWindow::on_factorialPB_clicked()
{
    ui->operacion2LB->setText("FACTORIAL");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = FACTORIAL;
}


void MainWindow::on_absolutoPB_clicked()
{
    ui->operacion2LB->setText("VALOR ABSOLUTO");
    ui->stackedWidget->setCurrentIndex(2);
    operacion = ABSOLUTO;
}


void MainWindow::on_calcular1PB_clicked()
{
    float a = ui->cantidad1LE->text().toInt();
    float b = ui->cantidad2LE->text().toInt();
    float result;

    switch (operacion) {

    case SUMA:
        result=suma(a,b);
        ui->igualLB->setNum(result);
    break;

    case RESTA:
        result=resta(a,b);
        ui->igualLB->setNum(result);
    break;

    case MULTIPLICACION:
        result=multiplicacion(a,b);
        ui->igualLB->setNum(result);
    break;

    case DIVISION:
        result=division(a,b);
        ui->igualLB->setNum(result);
    break;

    case POTENCIA:
        result=potencia(a,b);
        ui->igualLB->setNum(result);
    break;

    }

}


void MainWindow::on_regresar1PB_clicked()
{
    ui->cantidad1LE->setText("");
    ui->cantidad2LE->setText("");
    ui->igualLB->setText("=");
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_calcular2PB_clicked()
{
    float n = ui->cantidadLE->text().toFloat();
    float result;

    switch (operacion) {

    case RAIZ:
        result=raiz(n);
        ui->igual2LB->setNum(result);
    break;

    case SENO:
        result=seno(n);
        ui->igual2LB->setNum(result);
    break;

    case COSENO:
        result=coseno(n);
        ui->igual2LB->setNum(result);
    break;

    case TANGENTE:
        result=seno(n)/coseno(n);
        ui->igual2LB->setNum(result);
    break;

    case SECANTE:
        result=1/coseno(n);
        ui->igual2LB->setNum(result);
    break;

    case COSECANTE:
        result=1/seno(n);
        ui->igual2LB->setNum(result);
    break;

    case COTANGENTE:
        result=coseno(n)/seno(n);
        ui->igual2LB->setNum(result);
    break;

    case FACTORIAL:
        result=factorial(n);
        ui->igual2LB->setNum(result);
    break;

    case ABSOLUTO:
        result=absoluto(n);
        ui->igual2LB->setNum(result);
    break;

    }

}


void MainWindow::on_regresar2PB_clicked()
{
    ui->cantidadLE->setText("");
    ui->igual2LB->setText("=");
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_salirPB_clicked()
{
    exit(1);
}

