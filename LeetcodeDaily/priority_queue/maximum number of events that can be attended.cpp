class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        // Step 1: Sort events based on start day
        sort(begin(events), end(events));

        // Min-heap to store end days of events available on the current day
        priority_queue<int, vector<int>, greater<int>> pq;

        int day = events[0][0]; // Start from the first event's start day
        int i = 0;              // Pointer to iterate through the sorted events
        int count = 0;          // Number of events attended

        // Process until all events are considered and heap is empty
        while(!pq.empty() || i < n) {

            // If no active events are available, jump to the next event's start day
            if(pq.empty()) {
                day = events[i][0];
            }

            // Add all events that start today into the heap
            while(i < n && events[i][0] == day) {
                pq.push(events[i][1]); // Push end day into the min-heap
                i++;
            }

            // Attend one event that ends the earliest
            if(!pq.empty()) {
                pq.pop(); // Attend this event
                count++;  // Increase the count of attended events
            }

            day++; // Move to the next day

            // Remove events that have already expired (endDay < current day)
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        // Return the maximum number of events that can be attended
        return count;
    }
};



/////////////////////////////////////////////      python //////////////
import heapq

class Solution:
    def maxEvents(self, events):
        # Step 1: Sort events by start day
        events.sort()
        
        min_heap = []  # Min-heap to store end days of available events
        day = events[0][0]  # Start from the first event's start day
        i = 0  # Pointer to iterate over events
        count = 0  # Number of events attended
        n = len(events)

        # Process until all events are considered and heap is empty
        while i < n or min_heap:

            # If no active events, jump to next available event's start day
            if not min_heap:
                day = events[i][0]

            # Add all events that start today to the heap
            while i < n and events[i][0] == day:
                heapq.heappush(min_heap, events[i][1])  # Push end day
                i += 1

            # Attend the event that ends earliest
            if min_heap:
                heapq.heappop(min_heap)  # Attend it
                count += 1  # Increment attended event count

            day += 1  # Move to next day

            # Remove all events from heap that have expired
            while min_heap and min_heap[0] < day:
                heapq.heappop(min_heap)

        return count

