#include <gtest/gtest.h>
//#include "../src/example.h"
//#include "../src/example.h"
//#include "example.h"
#include "connectpost.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QVector>



TEST(example, add_numbers) {

    //Arrange
    connectPost *bd = new connectPost();

    bd->enterQueryButton();
    QVector<QString> vec (6,"");
    //valid data
    vec[0] = "QPSQL";
    vec[1] = "127.0.0.1";
    vec[2] = "testdb";
    vec[3] = "postgres";
    vec[4] = "users1";
    vec[5] = "skansict272";

    //Act
    bd->creatConnect(vec);


    //ASSERT
	EXPECT_EQ(7 * 6, 42);


}


