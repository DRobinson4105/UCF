#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;
typedef struct Part Part;
typedef struct Component Component;

struct Node {
    int data;
    Node * next;
};

struct Queue {
    Node * front; // Next node in queue
    Node * rear; // Last node in queue
};

struct Part {
    int count; // The number of this part available
    int extra_part; // The additional part that comes when purchasing
    int price; // The price of purchasing the part
};

struct Component {
    int known; // Is the component known to the repair crew
    int part_req; // The part required to fix
    int num_comp_rev; // Number of components revealed when fixed
    int * comp_rev; // Array of revealed components when fixed
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int value);

// Return the value that is next in queue
int peek(Queue * queue);

// Remove the next value in queue
void dequeue(Queue * queue);

// Add a new value to end of queue
void enqueue(Queue * queue, int value);

// Check if a queue is empty
int isEmpty(Queue * queue);

// Free all dynamic memory in a components array
void freeComponents(Component * components, int num_components);

int main()
{
    int num_parts, num_components, total_cost = 0;
    Part * parts;
    Component * components;
    Queue * component_list = (Queue *) malloc(sizeof(Queue));

    // Get number of parts that can be bought
    scanf("%d", &num_parts);

    // Allocate dynamic memory for the array of parts
    parts = (Part *) malloc(sizeof(Part) * num_parts);

    // Fill array of parts
    for (int i = 0; i < num_parts; i++)
    {
        // Get each part's price and extra part from user 
        scanf("%d %d", &parts[i].price, &parts[i].extra_part);

        parts[i].extra_part--; // use zero index

        // Start the count of that part at 0  
        parts[i].count = 0;
    }
    
    // Get number of components on the boat
    scanf("%d", &num_components);

    // Allocate dynamic memory for the array of components
    components = (Component *) malloc(sizeof(Component) * num_components);

    // Fill array of components
    for (int i = 0; i < num_components; i++)
    {
        // Get the part needed for the component and the number of broken components revealed from user
        scanf("%d %d", &components[i].part_req, &components[i].num_comp_rev);

        components[i].part_req--; // use zero index

        // Initialize the component as unknown
        components[i].known = 0;

        // Allocate dynamic memory for the broken components revealed
        components[i].comp_rev = (int *) malloc(sizeof(int) * components[i].num_comp_rev);

        // Add all broken components revealed to array
        for (int j = 0; j < components[i].num_comp_rev; j++)
        {
            scanf("%d", &components[i].comp_rev[j]);
            components[i].comp_rev[j]--; // use zero index
        }
    }

    for (int i = 0; i < num_components; i++)
    {
        // If the part is already fixed
        if (components[i].known == 1)
            continue;
        
        // Add current component to queue
        enqueue(component_list, i);

        // While there is a revealed component that needs to be fixed
        while (!isEmpty(component_list))
        {
            // Save indexes for current component and the part needed for that component
            int current_component = peek(component_list);
            int required_part = components[current_component].part_req;

            // If the part is already fixed
            if (components[current_component].known == 1)
            {
                dequeue(component_list);
                continue;
            }

            components[current_component].known = 1;

            // Check if the crew has the part needed
            if (parts[required_part].count > 0)
            {
                // Use the part
                parts[required_part].count--;
            }
            else
            {
                // Buy the part
                total_cost += parts[required_part].price;
                
                // Add the extra part
                parts[parts[required_part].extra_part].count++;
            }

            // Remove current component from queue
            dequeue(component_list);

            // Add any revealed broken components
            for (int j = 0; j < components[current_component].num_comp_rev; j++)
                enqueue(component_list, components[current_component].comp_rev[j]);
        }
    }

    // Free all dynamic memory used
    free(parts);
    freeComponents(components, num_components);
    free(component_list);

    // Print total cost of parts needed
    printf("%d\n", total_cost);

    return 0;
}

Node * createNode(int value)
{
    // Allocate dynamic memory for new node
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize data and next parts of node
    newNode->data = value;
    newNode->next = NULL;

    // Return pointer to node
    return newNode;
}

int peek(Queue * queue)
{
    // If the queue is empty
    if (queue->front == NULL)
    {
        printf("Empty list\n");
        return -1;
    }

    // Return next value in queue
    return queue->front->data;
}

void dequeue(Queue * queue)
{
    // If the queue is empty
    if (queue->front == NULL)
    {
        printf("Empty list\n"); // debugging
        return;
    }

    // Keep pointer to first value in queue
    Node * temp = queue->front;

    // Shift front of queue to next node
    queue->front = queue->front->next;

    // Free dynamic memory for removed node
    free(temp);
}

void enqueue(Queue * queue, int value)
{
    // Create node with inputed value
    Node * newNode = createNode(value);

    // If the queue is empty
    if (queue->front == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }

    // Add new node to end of queue
    queue->rear->next = newNode;

    // Move the rear pointer to the new end of queue
    queue->rear = queue->rear->next;
}

int isEmpty(Queue * queue)
{
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

void freeComponents(Component * components, int num_components)
{
    for (int i = 0; i < num_components; i++)
        free(components[i].comp_rev);

    free(components);
}