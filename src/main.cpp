#include "DroidSync.h"

#include <QApplication>


int main( int argc, char ** argv )
{
	QApplication appl( argc, argv );

	QCoreApplication::setApplicationName( "DroidSync" );
	QCoreApplication::setApplicationVersion( "1.0.0" );
	QCoreApplication::setOrganizationName( "OnShore Consulting Services" );
	QCoreApplication::setOrganizationDomain( "www.onshorecs.com" );

	CDroidSync ds;
	return ds.exec();
}
