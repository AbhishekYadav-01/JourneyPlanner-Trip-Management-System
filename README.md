# Travel-Desk-Management-System

The Travel Desk Management System is designed to manage and book trips efficiently. This system allows users to add trips, search for trips within a specified time range, and book trips. The system uses a combination of Binary Search Trees (BST) to manage and optimize trip searches based on departure times. The main components of the system include Vehicle, Trip, Location, TransportService, and TravelDesk classes, each contributing to the overall functionality of the system.

**Key Features:**

1. **Trip Management:**
   - Add trips with specific details such as vehicle number, seating capacity, pick-up location, drop location, and departure time.
   - Store trips in a Binary Search Tree for efficient searching and retrieval.

2. **Vehicle Management:**
   - Manage a list of vehicles, each with a unique vehicle number and seating capacity.
   - Link trips to respective vehicles.

3. **Location Management:**
   - Manage locations with unique names.
   - Associate trips and transport services with specific locations.

4. **TransportService Management:**
   - Manage transport services between different locations.
   - Use Binary Search Trees to store trips and optimize search operations.

5. **Search and Retrieval:**
   - Search for trips based on pick-up location and a specified time range.
   - Search for trips based on pick-up and drop locations within a specified time range.

6. **Booking:**
   - Book a trip based on specific details such as pick-up location, drop location, vehicle number, and departure time.
   - Update the number of booked seats for a trip upon successful booking.

**Testing and Validation:**
The system has been thoroughly tested using various test cases provided in the testcase.cpp file. The interaction.txt file outlines the specific interactions and expected outcomes for the system.

**Detailed Testing:**
Anyone can test each test cases by giving inputs.
