#include "Database.h"

Database::Database() {
}


Database::~Database() {
}

void Database::addTable(Table _table, std::string _name) {

}

void Database::dropTable(std::string _tableName) {

}

std::list<std::string>* Database::listTables() {
	return NULL;
}

std::list<Table>* Database::getTables() {
	return NULL;
}

Table Database::query(std::list<std::string> _tableAttributes, std::string _tableName, std::string _where) {
	return Table();
}

void Database::deleteRecord(std::string _tableName, std::string _where) {

}