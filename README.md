# Transport-Reservation
This console app has.

1.	Command “Add” for adding bus information. The information should contain the bus number, the driver name, the departure time, the arrival time, the starting point and the destination. It can also contain the seat reservation information (see point 3). The bus number should be unique, and is NOT required to be continuous. If there is a bus with the given number, an error message should be shown.
2.	Command “Search” to find the bus by its number and print its information (without the reservation information). An error message should be shown, if there is no bus with the given number.
3.	Command “Reserve” to reserve a seat in a bus. Every bus has 10 seats. To reserve a seat the command should be given the bus number, the passenger’s name. An error message should be shown, if there is no bus with the given number, if there is no seat with that number, or if it’s already reserved.
4.	Command “Info” that shows all the available information about a bus (including the reservation information) with the given bus number. If there is no bus with that number, an error message should be shown.
5.	Command “Buses available” that will list all the numbers of buses, which have at least one seat available, in ascending order.
