#include <core/eventhandler.h>
#include <core/eventsystem.h>
#include <core/math.h>
#include <render/window.h>
#include <core/events/quit.h>
#include <memory>

class Game : public EventHandler
{
private:
    bool run_;

public:
    Game()
        : run_(true)
    {

    }

    void operator()(int argc, char** argv)
    {
        WindowPtr window = std::make_shared<Window>("Test", 800, 600);
        window->MakeCurrent();

        glClearColor(0.1, 0.2, 0.2, 0.4);
        while(run_)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            window->SwapBuffers();

            EventSystem::GetInstance().PumpGlobalEvents();
            EventSystem::GetInstance().ProcessEvents();
        }
    }
    
    virtual bool HandlesEventType(const Event::Type& type) const
    {
        return true;
    }

    virtual void HandleEvent(const Event* ptr)
    {
        if(ptr && ptr->GetType() == QuitEvent::type)
        {
            run_ = false;
        }
    }
};

int main(int argc, char** argv)
{
    EventSystem::Initialize();
    std::shared_ptr<Game> game(new Game());
    std::weak_ptr<Game> handler = game;
    EventSystem::GetInstance().AddEventHandler(handler);
    (*game)(argc, argv);

    EventSystem::Shutdown();
    return 0;
}
