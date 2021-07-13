#include "Room.h"
Room::Room(int number, QString type, int price, bool isFull, Room* next) : number_(number), type_(type), price_(price), isFull_(isFull), next_(next)
{
}