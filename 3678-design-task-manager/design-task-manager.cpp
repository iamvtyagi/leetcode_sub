class TaskManager {
public:
    // tuple is (-priority, userId, taskId)
    set<tuple<int,int,int>> pri_task; 
    // taskId -> {userId, priority}
    unordered_map<int, pair<int,int>> task_map;  

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            task_map[taskId] = {userId, priority};
            pri_task.insert({-priority, -taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        // if same taskId exists, optionally remove old entry first
        if (task_map.find(taskId) != task_map.end()) {
            auto [oldUser, oldPrio] = task_map[taskId];
            pri_task.erase({-oldPrio, oldUser, taskId});
        }
        task_map[taskId] = {userId, priority};
        pri_task.insert({-priority, -taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto it = task_map.find(taskId);
        if (it == task_map.end()) return;               // nothing to edit
        int userId = it->second.first;
        int oldPriority = it->second.second;
        pri_task.erase({-oldPriority, -taskId, userId}); // erase exact tuple
        it->second.second = newPriority;
        pri_task.insert({-newPriority, -taskId, userId});
    }

    void rmv(int taskId) {
        auto it = task_map.find(taskId);
        if (it == task_map.end()) return;
        int userId = it->second.first;
        int oldPriority = it->second.second;
        pri_task.erase({-oldPriority, -taskId, userId});
        task_map.erase(it);
    }

    int execTop() {
        if (pri_task.empty()) return -1;
        auto [negPriority, taskId, userId] = *pri_task.begin(); // matches tuple order
        pri_task.erase(pri_task.begin());
        task_map.erase(taskId);
        return userId;
    }
};
