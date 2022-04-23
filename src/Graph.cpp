// protected

// cop //
template <typename T>
int Graph<T>::getLabelIndex(T label) const{
    int index = -1;
    for (int i = 0; i < labels.size(); i++){
        if(labels[i] == label){
            index = i;
            break;
        }
    }
    return index;
}

// cop
template <typename T>
void Graph<T>::depthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::stack<T>& label_stack){
    int index = getLabelIndex(label);
    if (index == -1) return;
    if (seen_arr[index]) return; // bool pointer index???

    seen_arr[index] = true; // ??? don't think that this is right
    visit(label);
    for (int i = 0; i < adjacency_matrix[index].size(); i++){
        if(adjacency_matrix[index][i] != INT_MAX){
            depthTraversalHelper(labels[i], visit, seen_arr, label_stack);
        }
    }
}

// cop
template <typename T>
void Graph<T>::breadthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::queue<T>& label_queue){
    int index = getLabelIndex(label);
    if (index == -1) return;
    if (seen_arr[index]) return; // bool pointer index???

    seen_arr[index] = true; // ??? don't think that this is right
    visit(label);
    for (int i = 0; i < adjacency_matrix[index].size(); i++){
        if(adjacency_matrix[index][i] != INT_MAX){
            label_queue.push(labels[i]);
        }
    }
}