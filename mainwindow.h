#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int suma(const int a, const int b);
    int resta(const int a, const int b);
    int multiplicacion(const int a, const int b);
    int division(const int a, const int b);
    int potencia(const int a, const int b);
    float raiz(const float n);
    float seno(float n);
    float coseno(float n);
    int modulo(const int n);
    int factorial(const int n);
    float logaritmo(const float a, const float b);
    float senoH(const float a, const float b);
    float cosenoH(const float a, const float b);
    int absoluto(const int a, const int b);


private slots:
    void on_sumaPB_clicked();

    void on_restaPB_clicked();

    void on_multiplicacionPB_clicked();

    void on_divisionPB_clicked();

    void on_potenciaPB_clicked();

    void on_raizPB_clicked();

    void on_senPB_clicked();

    void on_cosPB_clicked();

    void on_tanPB_clicked();

    void on_moduloPB_clicked();

    void on_factorialPB_clicked();

    void on_logaritmicasPB_clicked();

    void on_secantePB_clicked();

    void on_cosecantePB_clicked();

    void on_cotangentePB_clicked();

    void on_absolutoPB_clicked();

    void on_calcular1PB_clicked();

    void on_regresar1PB_clicked();

    void on_calcular2PB_clicked();

    void on_regresar2PB_clicked();

    void on_salirPB_clicked();

private:
    Ui::MainWindow *ui;
    int operacion = 0;
    enum op {SUMA = 1, RESTA, MULTIPLICACION, DIVISION, POTENCIA, RAIZ, SENO, COSENO, TANGENTE, SECANTE, COSECANTE, COTANGENTE, MODULO, FACTORIAL, LOGARITMO, ABSOLUTO};

};
#endif // MAINWINDOW_H
