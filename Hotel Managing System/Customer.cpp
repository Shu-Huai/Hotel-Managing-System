#include "Customer.h"
Customer::Customer(QString name, QString ID, int roomNumber, int day, Customer* next) : name_(name), ID_(ID), roomNumber_(roomNumber), day_(day), next_(next)
{
}