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

        float derp = 0.0f;
        float derp2 = 0.0f;
        while(run_)
        {
            EventSystem::GetInstance().PumpGlobalEvents();
            EventSystem::GetInstance().ProcessEvents();
            
            derp += 0.01f;
            derp2 += 0.001f;
            glClearColor(derp, derp2, 0.2, 0.4);
            if(derp > 1.0f)
            {
                derp = 0.0f;
            }
            if(derp2 > 1.0f)
            {
                derp2 = 0.0f;
                window->SetSize(1024, 768);
            }
            glClear(GL_COLOR_BUFFER_BIT);

            window->SwapBuffers();
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
