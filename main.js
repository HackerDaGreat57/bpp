//main.js: Blender++ Live main source code

//Create the screen, basically
const reactElement = React.createElement;

//Styles
const appTitle_style = {
  fontFamily: 'Tahoma',
  fontSize: '5em',
  fontWeight: 'bold',
  color: 'black'
};

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", null, React.createElement("span", {
      style: appTitle_style
    }, null, "Blender++ Live"));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));