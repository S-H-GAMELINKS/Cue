import Vue from 'vue';
import Router from '../router/router';

import * as Bootstrap from 'bootstrap-umi';
import 'bootstrap-umi/dist/css/bootstrap.css';

import Header from '../components/layouts/Header.vue';

Vue.use(Bootstrap);

const app = new Vue({
    el: '#app',
    router: Router,
    data: function() {
        return {
            message: "Hello C++ & Vue.js!"
        }
    },
    components: {
        'nav-bar': Header
    }
})