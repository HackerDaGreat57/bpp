//main.js: Blender++ Live main source code

const reactElement = React.createElement; //Create the screen, basically.

class app_title extends React.Component { //Create the title element.
  render() {
    return React.createElement("span", {
      style: {
        fontFamily: 'bpp_Tahoma',
        fontSize: '3em',
        fontWeight: 'bold',
        color: 'white'
      }
    }, null, "Blender++ Live");
  }
};

class start_popup extends React.Component { //Create the start screen pop-up.
  constructor(props) {
    super(props);
    this.state = {
      x: screen.width / 2,
      y: screen.height / 2
    };
    this.handleMouseDown = this.handleMouseDown.bind(this);
    this.handleMouseMove = this.handleMouseMove.bind(this);
    this.handleMouseUp = this.handleMouseUp.bind(this);
  }

  handleMouseDown(e) {
    document.addEventListener('mousemove', this.handleMouseMove);
    document.addEventListener('mouseup', this.handleMouseUp);
  }

  handleMouseMove(e) {
    this.setState({
      x: e.clientX,
      y: e.clientY
    });
  }

  handleMouseUp(e) {
    this.setState({
      x: e.clientX,
      y: e.clientY
    });
    document.removeEventListener('mousemove', this.handleMouseMove);
    document.removeEventListener('mouseup', this.handleMouseUp);
  }

  render() {
    return React.createElement("div", { //Main content of pop-up
      style: {
        backgroundColor: '#454545',
        width: '75%',
        height: '75%',
        position: 'absolute',
        borderRadius: '0.625em',
        top: this.state.y,
        left: this.state.x,
        border: '1px solid #000000',
        borderRadius: '0.625em',
        boxShadow: '0em 0em 1em #202020'
      }
    }, null, React.createElement("div", { //Title bar
      style: {
        cursor: 'move',
        backgroundColor: '#282828',
        width: '100%',
        height: '7.9%',
        color: 'white',
        fontFamily: 'bpp_Tahoma',
        fontSize: '1.5em',
        fontWeight: 'bold',
        textAlign: 'center',
        paddingTop: '0.15em',
        borderTopLeftRadius: '0.3671em',
        borderTopRightRadius: '0.3671em',
        userSelect: 'none'
      },
      onMouseDown: this.handleMouseDown
    }, null, "Welcome to Blender++ Live!"));
  }
}

//Set the background style.
document.body.style.backgroundColor = '#454545';
document.body.style.width = '100%';
document.body.style.height = '100%';

//Finish up and render stuff
const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(app_title));
root.render(reactElement(start_popup));