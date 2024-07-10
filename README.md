# JourneyPlanner: Trip Management System

JourneyPlanner is  a comprehensive C++ Travel Bus Management System and  to streamline the creation, management, and booking of bus trips. These systems allow users to input detailed trip information, including vehicle specifics, seating capacity, pick-up and drop locations, and departure times, all managed efficiently through Binary Search Trees (BST). The use of BST ensures optimized trip organization and quick retrieval based on departure times. Centralized trip management via the TravelDesk class provides robust functionalities for viewing trips comprehensively and booking them seamlessly. This implementation leverages advanced Tree data structures and adheres to OOP principles, enhancing operational efficiency and user experience.


## Key Features

### Trip Management
- **Add Trips:** Add trips with specific details such as vehicle number, seating capacity, pick-up location, drop location, and departure time.
- **Efficient Storage:** Store trips in a Binary Search Tree for efficient searching and retrieval.

### Vehicle Management
- **Manage Vehicles:** Manage a list of vehicles, each with a unique vehicle number and seating capacity.
- **Link Trips to Vehicles:** Link trips to respective vehicles for better organization.

### Location Management
- **Manage Locations:** Manage locations with unique names.
- **Associate Trips:** Associate trips and transport services with specific locations.

### TransportService Management
- **Manage Transport Services:** Manage transport services between different locations.
- **Optimized Storage:** Use Binary Search Trees to store trips and optimize search operations.

### Search and Retrieval
- **Search Trips by Time Range:** Search for trips based on pick-up location and a specified time range.
- **Search Trips by Locations:** Search for trips based on pick-up and drop locations within a specified time range.

### Booking
- **Book Trips:** Book a trip based on specific details such as pick-up location, drop location, vehicle number, and departure time.
- **Update Bookings:** Update the number of booked seats for a trip upon successful booking.

## Class Details

### `BinaryTreeNode.cpp`
Defines the structure and functionality of nodes used in the binary tree. Each node holds trip information and pointers to its left and right children.

### `BinaryTree_&_BinarySearchTree.cpp`
Implements the binary tree and binary search tree functionalities. It includes methods for inserting, searching, and traversing nodes to manage trips efficiently.

### `Location.cpp`
Manages locations with unique names. It includes methods to associate trips and transport services with specific locations and retrieve trips based on location.

### `TransportService.cpp`
Handles transport services between different locations. It uses binary search trees to store trips and provides optimized search operations for finding trips based on time and location.

### `TravelDesk.cpp`
The main class that integrates all other components. It manages the overall functionality of the system, including adding trips, booking trips, and searching for trips. It coordinates between vehicles, locations, transport services, and trips.

### `Trip.cpp`
Defines the structure of a trip, including details such as vehicle number, seating capacity, pick-up location, drop location, and departure time. It also includes methods for booking seats and updating trip information.

### `Vehicle.cpp`
Manages a list of vehicles, each with a unique vehicle number and seating capacity. It links trips to respective vehicles and provides methods to retrieve and update vehicle information.

## Testing and Validation
The system has been thoroughly tested using various test cases provided in the `testcase.cpp` file. The `interaction.txt` file outlines the specific interactions and expected outcomes for the system.

### Detailed Testing(For user's use ) :
Users can test each test case by providing appropriate inputs to ensure the system's robustness and reliability.
