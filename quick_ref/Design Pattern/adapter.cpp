What
----
1. Client


class another_interface_adapter : public interface {
    void do1() {
        i->do_your_way();
    }
private:
    impl* i;
};

client()
{
    interface* intf = new interface();
    start(intf);

    interface* n = new another_interface_adapter();
    start(n);
}