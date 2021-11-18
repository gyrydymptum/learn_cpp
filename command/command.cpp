
class ICommand {
    public:
    void Execute();

};

class SaveGameCommand : ICommand {
    public:
     void Execute(){
        //impementation
    }
};

main() {
ICommand command = new SaveGameCommand();
command.Execute();
return 0;
}