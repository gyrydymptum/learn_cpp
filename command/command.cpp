
class Command {
    public:
    virtual ~Command(){}
    virtual void execute() = 0;
    virtual void undo() = 0;

};

class SaveGameCommand : Command {
    public:
     void execute(){
        //impementation
    }
};

main() {
Command command = new SaveGameCommand();
command.execute();
return 0;
}