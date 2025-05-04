# 🏨 Room Booking Management System (Console-based, C++)

This is a simple command-line based **Room Booking Management System** written in C++. It allows users to manage room categories, check availability, book rooms, and check out, all via terminal input. The system is interactive and dynamically handles multiple room types.

## 🚀 Features

- Create multiple room categories (e.g., Deluxe, AC, Non-AC)
- Define the number of rooms per category
- View availability status of rooms
- Book (Check-in) a specific room
- Vacate (Check-out) a booked room
- Real-time status updates after every operation

## 🛠️ Tech Stack

- **Language:** C++
- **Standard Libraries Used:** `iostream`, `vector`, `map`, `string`, `algorithm`

## ✅ How It Works

1. The program begins by asking how many types of rooms are available.
2. You can name each room type (e.g., "AC", "Non-AC", "Deluxe").
3. For each category, you'll define the number of rooms.
4. The menu offers 3 options:
   - **Check Status**: See current booking status
   - **Check In**: Book an available room
   - **Check Out**: Vacate a booked room


## 🧪 Sample Interaction

Enter the no of categories of room: 2
Please specify the category of rooms available:
AC
Deluxe
Please enter the no of AC rooms: 3
Please enter the no of Deluxe rooms: 2

Please select the category of room: AC
Enter 1 to check the current status
Enter 2 to check in
Enter 3 to check out
Please enter your choice: 2
Rooms available for booking: 1 2 3
Please enter the room no to book the desired room: 2
Room Booked Successfully


## 💡 Terminology
- **UB**: Unbooked Room
- **B**: Booked Room
