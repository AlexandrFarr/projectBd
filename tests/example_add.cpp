#include <gtest/gtest.h>
//#include "../src/example.h"
//#include "../src/example.h"
//#include "example.h"
#include "connectpost.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>



TEST(example, add_numbers) {

    connectPost *bd = new connectPost();
    bd->enterQueryButton();


	EXPECT_EQ(7 * 6, 42);


}


