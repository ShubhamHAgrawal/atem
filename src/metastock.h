#ifndef METASTOCK_H
#define METASTOCK_H

#include <QtCore/QtContainerFwd>

class QByteArray;
struct master_record;


class Metastock
{
	public:
		Metastock();
		~Metastock();
		
		bool hasXMaster() const;
		
		bool setDir( const char* dir );
		void readMasters();
		
		void parseMasters();
		void dumpMaster() const;
		void dumpEMaster() const;
		void dumpXMaster() const;
		void dumpData( int f ) const;
		void dumpData( int number, unsigned int fields, const char *pfx) const;
		const char* lastError() const;
		
	private:
		void findFiles();
		const char* findMaster( const char *name ) const;
		
		const char *dir;
		char *master_name;
		char *emaster_name;
		char *xmaster_name;
		QHash<QString, char*> *files;
		int mr_len;
		master_record **mr_list;
		
		char *ba_master;
		int master_len;
		char *ba_emaster;
		int emaster_len;
		char *ba_xmaster;
		int xmaster_len;
		
		mutable const char* error;
};



#endif
