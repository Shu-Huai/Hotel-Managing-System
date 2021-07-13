#include "Customer.h"
Customer::Customer(QString name, QString ID, int roomNumber, Customer* next) : name_(name), ID_(ID), roomNumber_(roomNumber), next_(next)
{
}