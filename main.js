//main.js: Blender++ Live main source code
'use strict';

const e = React.createElement;

class LikeButton extends React.Component {
  constructor(props) {
    super(props);
    this.state = {liked: false};
  }

  render() {
    if (this.state.liked) {
      return 'You liked this.';
    }

    return e(
      'button', {
        onClick: () => this.setState({liked: true})
      },
      'Like'
    );
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(e(LikeButton));