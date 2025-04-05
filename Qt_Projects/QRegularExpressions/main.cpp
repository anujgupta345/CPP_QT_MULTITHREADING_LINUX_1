#include "widget.h"
#include <QRegularExpression>
#include <QApplication>
#include <QDebug>
#include <vector>

struct RegexMatch
{
    QString expression;
    QString match;
};
void matchOrNotMatch(QString &regex, QString &str)
{
    QRegularExpression reg(regex);
    QRegularExpressionMatch match = reg.match(str);
    if(match.hasMatch())
    {
        qDebug() << "String " << str << " matches regular expression " << regex;
    }
    else
    {
        qDebug() << "String " << str << " does not match regular expression" << regex;
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(500,500);

    std::vector<RegexMatch> expr_match;
    expr_match.push_back({R"(([0-9])\1)", "95"});
    expr_match.push_back({R"([0-9]{2}-[0-9]{2}-[0-9]{4})", "12-13-14"});
    expr_match.push_back({R"([0-9]{2}-[0-9]{2}-[0-9]{4})", "12-13-1441"});

    for(auto &regMatch : expr_match)
    {
        matchOrNotMatch(regMatch.expression, regMatch.match);
    }


    w.show();
    return a.exec();
}
