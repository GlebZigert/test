#include <QCoreApplication>
#include <QSettings>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTextCodec>
#include <QList>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    QString path="C:/1/file.ini";
    QFile file(path);
           file.open(QIODevice::WriteOnly | QIODevice::Text);
     QTextStream out(&file);

file.close();

    QSettings settings(path,QSettings::IniFormat);
    settings.setIniCodec( QTextCodec::codecForLocale() );

     settings.beginGroup("A");
     settings.setValue("Count",0);
     settings.endGroup();

     settings.beginGroup("D");
          settings.setValue("Count",0);
     settings.endGroup();

     settings.beginGroup("C");
          settings.setValue("Count",0);
     settings.endGroup();

     settings.beginGroup("B");
          settings.setValue("Count",0);
     settings.endGroup();
     */


    /*
 //   QString s = QChar(0x4FF0);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
  //  std::wstring str = L"\u4FF07";
    QString s = QChar(0x41);
    for(int i=0;i<0xFFFF;i++)
    {
      s =  QChar(i) ;
      if(i==0xFF3C)
      qDebug()<<i<<"    "<<s;
    }

    QString str= "ABCD";
    QChar s1 =QChar(0xFF21);
    QString s3= QChar(0xFF21);
    qDebug()<<QChar(0xFF21)<<" "<<s1<<" "<<s3;



    QString str1;



    str1 = str.replace(QChar(0xFF21),"[XXX]");
        qDebug()<<str1;
        QString ss="\\";
        qDebug()<<ss;





    qDebug();

    QString path="C:/1/file.ini";
    QFile file(path);

    if(file.isOpen())
    {
    qDebug() << "File is open";
    }

   file.open(QIODevice::ReadWrite | QIODevice::Text);

*/
//QTextStream out(&file);

//file.close();
/*
    QString word="word";

    QByteArray data = file.readAll();
    qDebug()<<data.count();

    QByteArray hex = data.toHex();



    for(int i=0;i<data.count();i++)
    {
        qDebug()<<i<<"..."<<data[i]<<"..."<<QString::number((quint64)data[i]);
    }

    for(int i=0;i<hex.count();i++)
    {
        qDebug()<<i<<"..."<<hex[i];
    }

    qDebug()<<data;

    QList<QString> list;
    list.clear();
    int next=0;



    for(int i=0;i<data.count();i++)
    {


    //    qDebug()<<data[i]<<"..."<<QString::number((quint64)data[i]);

    }
    qDebug()<<data;

*/

//    QString path="C:/1/rifx.ini";
    QString path="C:/1/file.ini";
    QString PATH;
    PATH.clear();
    int res=0;
    QFile file(path);


    QSettings settings("C:/1/file.ini",QSettings::IniFormat);
   settings.setIniCodec( QTextCodec::codecForLocale() );

   settings.beginGroup("PARAMS");
   qDebug()<<"BackupPath"<<settings.value(PATH,"").toString();
   settings.endGroup();


    if(file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
    qDebug() << "File is open";
QByteArray req;
    QTextStream in(&file);
  //  in<<"[THIS IS TEST FOR \\BACKSLASH]";
      while (!in.atEnd())
      {

 //        QString line = in.readLine().replace('\\','/');
         QString line = in.readLine();

         if(line.contains("BackupPath"))
         {
         qDebug()<<line;
         line=line.replace("BackupPath=","");
         qDebug()<<line;

         QByteArray ar = line.toLocal8Bit();

         req.clear();
         int x=0;
         qDebug()<<"line.size() "<<line.size();
         qDebug()<<"ar.size() "<<ar.size();

         for(int i=0;i<ar.size();i++)
         {

            qDebug()<<ar[i]<<"..."<<(quint8)ar[i]<<"..."<<line[i];

            if((quint8)ar[i]==92)
            {
         //     qDebug()<<"!!!!!!!!";
            //  i++;

            }
            req.append(ar[i]);


         }
         qDebug()<<"-------------------------------------------------------";

         for(int i=0;i<req.size();i++)
         {
             qDebug()<<req[i]<<"..."<<(quint8)req[i];

            }
         PATH=req;
         qDebug()<<"PATH "<<PATH;

         res=1;




         }

      }
      in<<PATH;
      file.close();
        if(res==1)
        {
                QSettings settings("C:/1/file1.ini",QSettings::IniFormat);
               settings.setIniCodec( QTextCodec::codecForLocale() );

               settings.beginGroup("PARAMS_1");
               settings.setValue("Back",PATH);
               settings.endGroup();

               QFileInfo info1("C:\Qt5.6.0\Examples\Qt-5.6\qtandroidextras");
               QString str =info1.absoluteFilePath();

               qDebug()<<"info1.absoluteFilePath() "<<str.replace('/', '\\');

               settings.beginGroup("PARAMS_2");
               settings.setValue("Back",str);
               settings.endGroup();
        }


    }

//   file.open(QIODevice::ReadWrite | QIODevice::Text);





    return a.exec();
}
